make:
	make -j8 -C build
clean:
	make -j8 -C build clean
run: make
	./build/WombatStudio
