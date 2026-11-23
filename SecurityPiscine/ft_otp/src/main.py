from . import TOTP, cli

def store_key(key):
	filename = "./ft_otp.key"
	with open(filename, "wt") as f:
		f.write(key)

def retrieve_key(filename):
	with open(filename, "rt") as f:
		key = f.read().strip()
		return key

def main():
	args = cli.argumentparser()
	if args.g is not None:
		store_key(args.g)
	if args.k is not None:
		key = retrieve_key(args.k)
		TOTP.totp(key)

if __name__ == '__main__':
	main()