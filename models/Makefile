generate: models.hpp

clean:
	rm -f models.cpp models.hpp models.cy

models.cy: enginemodels.cy editormodels.cy
	cat enginemodels.cy editormodels.cy > models.cy
models.hpp: models.cy
	cyborgbear -i models.cy -o models -n models -t cpp-qt -lc
	rm -f models.cy
