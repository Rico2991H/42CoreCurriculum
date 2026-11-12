from . import scraper, cli

def main() :
	max_depth = 0
	args = cli.argumentparser()
	if  args.r :
		if args.l:
			max_depth = args.l
	scraper.init_scraper(args.url, max_depth, args.p)

main()