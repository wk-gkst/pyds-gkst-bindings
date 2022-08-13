NAME=pyds_gkst
PKGS="gstreamer-1.0 gstreamer-video-1.0"
NVDS_VERSION="6.1"
NVDS_PATH="/opt/nvidia/deepstream/deepstream-${NVDS_VERSION}/sources/includes/"

c++ -O3 -Wall -shared -std=c++11 \
    -fPIC `python3 -m pybind11 --includes` \
    src/pyds_gkst.cpp \
    -o ${NAME}.so \
    -I${NVDS_PATH} -I/tmp/msgconv/ds-nvmsgconv/deepstream_schema/  \
    `pkg-config --cflags ${PKGS}`