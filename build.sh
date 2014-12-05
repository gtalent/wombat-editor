mkdir -p build
pushd build
qmake -spec linux-clang ../
#qmake -spec linux-clang QMAKE_CXXFLAGS+="-fsanitize=address -fno-omit-frame-pointer" \
#QMAKE_CFLAGS+="-fsanitize=address -fno-omit-frame-pointer -g" \
#QMAKE_LFLAGS+="-fsanitize=address" ../ \
#CONFIG+="debug"
make -j8
popd
