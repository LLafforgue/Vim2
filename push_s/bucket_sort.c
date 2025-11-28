#include "algo.h"
#include "ft_printf.h"
#include "push_swap.h"

int	racine(int n)
{
	int	rac;

	rac = 1;
	while (rac*rac <= n)
		rac++;
	return (rac - 1);
}

// void	bucket_sort(t_stacks *stacks)
// {
// 	t_stack	*a;
// 	t_stack	*b;
// 	int 	n_buckets;
// 	int 	repere;

// 	a = stacks->a;
// 	b = stacks->b;
// 	n_buckets = racine(a->len);
// 	repere = ft_search_max(a->values, a->len);
// 	while (a->len)
// 		ft_range_bicket(stacks)


// }

// Fonction auxiliaire : Trouve la valeur du k-ième quantile
int ft_find_quantile(int *values, int len, int k) {
    int *sorted = ft_copy_and_sort(values, len);
    int quantile = sorted[k];
    free(sorted);
    return quantile;
}

// Fonction pour transférer les éléments de a vers b selon le bucket courant
void ft_range_bucket(t_stacks *stacks, int max_in_bucket) {
    t_stack *a = stacks->a;
    t_stack *b = stacks->b;
    int pos = 0;
    while (pos < a->len) {
        if (a->values[0] < max_in_bucket) {
            pb(stacks);
            pos = 0; // Recommencer depuis le début après un pb
        } else {
            ra(stacks);
            pos++;
        }
    }
}

// Tri par insertion pour les petits buckets dans b
void ft_insertion_sort_b(t_stacks *stacks) {
    t_stack *b = stacks->b;
    int i = 1;
    while (i < b->len) {
        if (b->values[0] > b->values[1]) {
            sb(stacks);
            i = 0; // Recommencer depuis le début
        } else {
            rb(stacks); // Faire tourner pour vérifier le reste
            i++;
        }
    }
    // Remettre le plus petit élément en haut
    while (b->len > 0) {
        rrb(stacks);
    }
}

// Fonction principale : Bucket sort avec √n buckets
void bucket_sort(t_stacks *stacks) {
    t_stack *a = stacks->a;
    t_stack *b = stacks->b;
    int n = a->len;
    int n_buckets = racine(n); // racine(n) = (int)sqrt(n)
    int bucket_size = n / n_buckets;
    int *quantiles = malloc((n_buckets - 1) * sizeof(int));
    int current_bucket = 0;

    // Calculer les quantiles
    while (current_bucket < n_buckets - 1) {
        quantiles[current_bucket] = ft_find_quantile(a->values, n, (current_bucket + 1) * bucket_size);
        current_bucket++;
    }
    current_bucket = 0;

    // Transférer les éléments vers b par buckets
    while (current_bucket < n_buckets) {
        int max_in_bucket = (current_bucket == n_buckets - 1) ? ft_search_max(a->values, a->len) + 1 : quantiles[current_bucket];
        ft_range_bucket(stacks, max_in_bucket);
        // Trier le bucket dans b si sa taille est petite
        if (b->len <= 5) {
            ft_insertion_sort_b(stacks);
        }
        current_bucket++;
    }

    // Remonter les éléments triés de b vers a
    while (b->len > 0) {
        int insert_pos = 0;
        while (insert_pos < a->len && a->values[insert_pos] < b->values[0]) {
            insert_pos++;
        }
        // Amener l'élément de b au bon endroit dans a
        if (insert_pos < a->len / 2) {
            while (insert_pos-- > 0) {
                ra(stacks);
            }
        } else {
            while (insert_pos++ < a->len) {
                rra(stacks);
            }
        }
        pa(stacks);
    }

    free(quantiles);
}