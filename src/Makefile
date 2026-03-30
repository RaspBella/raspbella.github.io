.PHONY: default clean

default: gen
	mkdir -p ../docs/linux
	mkdir -p ../docs/media
	mkdir -p ../docs/game/steam
	mkdir -p ../docs/game/osu
	./gen

gen: gen.c
	cc $< -o $@

clean:
	rm -rf gen ../docs/index.html ../docs/{game,linux,media} ../docs/{gifs,images}/index.html
