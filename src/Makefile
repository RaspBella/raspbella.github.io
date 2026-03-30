.PHONY: default clean

default: gen
	mkdir -p ../docs/{linux,media}
	mkdir -p ../docs/game/{steam,osu}
	./gen

gen: gen.c
	cc $< -o $@

clean:
	rm -rf gen ../docs/index.html ../docs/{game,linux,media} ../docs/{gifs,images}/index.html
