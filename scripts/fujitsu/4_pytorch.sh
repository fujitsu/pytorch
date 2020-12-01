export USE_LAPACK=1
export USE_NNPACK=0
export USE_XNNPACK=0
export USE_NATIVE_ARCH=1
export MAX_JOBS=48

# Create venv
cd ${PYTORCH_INSTALL_PATH}
cd ${VENV_NAME}
source bin/activate

# Build PyTorch
cd ${PYTORCH_INSTALL_PATH}
cd ../../
cd third_party/ideep
cd mkl-dnn
cd src/cpu/aarch64/
mkdir -p build_xed_aarch64
cd build_xed_aarch64/
../xbyak_translator_aarch64/translator/third_party/xed/mfile.py --shared examples --cc="${TCSDS_PATH}/bin/fcc -Nclang -Kfast -Knolargepage" --cxx="${TCSDS_PATH}/bin/FCC -Nclang -Kfast -Knolargepage" install
cd kits
ln -sf xed-install-base-* xed
cd ..
export XED_BUILD_DIR=`pwd`
export XED_ROOT_DIR=${XED_BUILD_DIR}/kits/xed
export C_INCLUDE_PATH=${XED_ROOT_DIR}/include:${C_INCLUDE_PATH}
export LD_LIBRARY_PATH=${XED_ROOT_DIR}/lib:${LD_LIBRARY_PATH}

cd ../../../../../../../

python3 setup.py clean
python3 setup.py install
ln -sf ${XED_ROOT_DIR}/lib/libxed.so ${PREFIX}/.local/lib/libxed.so

