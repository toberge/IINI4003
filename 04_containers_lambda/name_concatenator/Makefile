.PHONY: run ccls

# I leave the scripts lying around for now

ccls:
	cmake -H. -BDebug -DCMAKE_BUILD_TYPE=Debug \
	                  -DCMAKE_EXPORT_COMPILE_COMMANDS=YES
	ln -s Debug/compile_commands.json .

run:
	bspc rule -a Name_concatenator state=floating
	cd build && make
	build/name_concatenator
