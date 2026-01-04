# Sample data
players = [
    {'name': 'alice', 'scores': 2300, 'activity': True, 'achievements': {'first_kill', 'level_10', 'treasure_hunter', 'boss_slayer', 'speed_run'}},
    {'name': 'bob', 'scores': 1800, 'activity': True, 'achievements': {'level_10', 'treasure_hunter', 'puzzle_master'}},
    {'name': 'charlie', 'scores': 2150, 'activity': False, 'achievements': {'first_kill', 'level_10', 'boss_slayer', 'speed_run', 'treasure_hunter', 'puzzle_master', 'legendary'}},
    {'name': 'sarah', 'scores': 1100, 'activity': True, 'achievements': {}}
    ]
regions = ['north', 'east', 'north', 'central']

# List Comprehension Examples
def analytics(players: list) -> None:
    """

    Args:

    Raise:
    """
    if type(players) is not list:
        raise TypeError(f"A list of player is needed !")
    for player in players:
        keys = set().union(player.keys())
        test_keys = {'name', 'activity', 'scores'} - keys
        if test_keys:
            raise KeyError(f"Missed {test_keys} in {player}")
    names, scores = zip(*[(player['name'], player['scores']) for player in players])
    high_scorers = [player for player, score in zip(names, scores) if score > 2000]
    doubled_scores = [score * 2 for score in scores]
    active_players = [player['name'] for player in players if player['activity']]
    print(f"High scorers (>2000): {high_scorers}")
    print(f"Scores doubled: {doubled_scores}")
    print(f"Active players: {active_players}")

# Output
print("=== Game Analytics Dashboard ===")
print("\n=== List Comprehension Examples ===")
try:
    analytics(players)
except (Exception, KeyError, TypeError) as e:
    print(e)

# Dict Comprehension Examples
names, scores = zip(*[(player['name'], player['scores']) for player in players])
player_scores = {player: score for player, score in zip(names, scores)}

score_categories = {}
score_categories['high'] = sum(1 for score in scores if score > 2000)
score_categories['medium'] = sum(1 for score in scores if 2000 >= score > 1000)
score_categories['low'] = sum(1 for score in scores if 1000 >= score)


achievement_counts = {player['name']: len(player['achievements']) for player in players}

print("\n=== Dict Comprehension Examples ===")
print(f"Player scores: {player_scores}")
print(f"Score categories: {score_categories}")
print(f"Achievement counts: {achievement_counts}")

