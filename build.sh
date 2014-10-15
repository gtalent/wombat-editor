mkdir -p build
pushd build
qmake -spec linux-clang ../
#qmake QMAKE_CXXFLAGS+="-fsanitize=address -fno-omit-frame-pointer" \
#QMAKE_CFLAGS+="-fsanitize=address -fno-omit-frame-pointer" \
#QMAKE_LFLAGS+="-fsanitize=address" ../
make -j8
popd
