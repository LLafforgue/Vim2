base = "0123456789abcdefghijklmnopqrstuvwxyz"

def digit_index(dig) -> int:
	index = 0
	for i in base:
		if i == dig:
			return index
		else:
			index += 1
	return 0

def convert10(num: str, base_from : int) -> int:
	dec = 0
	i = len(num) - 1
	for dig in num:
		dec += digit_index(dig) * base_from ** i
		i -= 1
	return dec

def convertbase(num : str , base_from : int, base_to : int) -> str:
	rev_num = ""
	new_num = ""
	dec = convert10(num, base_from)
	while dec > 0:
		rev_num += base[dec % base_to]
		dec = int(dec / base_to)
	end = len(rev_num) - 1
	for _ in rev_num:
		new_num += rev_num[end]
		end -= 1
	return new_num

print(convertbase("1011110", 2, 10))