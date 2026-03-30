.PHONY: default clean

default: gen
	./gen

gen: gen.c
	mkdir -p ../docs/{linux,media}
	mkdir -p ../docs/game/{steam,osu}
	cc -std=c23 $< -o $@

clean:
	rm -rf gen ../docs/index.html ../docs/{game,linux,media} ../docs/{gifs,images}/index.html
