.PHONY: run ccls

ccls:
	cmake -H. -BDebug -DCMAKE_BUILD_TYPE=Debug \
	                  -DCMAKE_EXPORT_COMPILE_COMMANDS=YES
	ln -s Debug/compile_commands.json .

build/example: main.cpp
	cd build && make

run: build/example
	bspc rule -a "SFML Example" state=floating
	build/example
