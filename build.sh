mkdir -p build
pushd build
qmake -spec linux-clang ../
make -j8
popd
