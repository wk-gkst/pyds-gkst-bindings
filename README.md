## pyds custom pybind11 for custom NVDSMETADATA

### Prerequisites

1. Install [pybind11](https://github.com/pybind/pybind11). The recommended way is to [build it from source](https://pybind11.readthedocs.io/en/stable/basics.html?highlight=install#compiling-the-test-cases). Alternatively you might try simply `pip3 install pybind11`.
2. You should have `gstreamer-1.0` and `gstreamer-video-1.0` packages installed in your system. If you are using DeepStream, you most likely installed these packages.
3. You will need also the standard `c++` compiler you usually find in Linux distributions. `c++11` standard is used.

### Compile the source

1. The source should be compiled on your target platform (Jetson or x86).
2. Set your DeepStream version and path in `build.sh`.
3. Launch `build.sh`
4. Install the compiled module with `python setup.py install` (use sudo or python3 if needed).


## Usage

`pyds_gkst` is meant to be used together with the standard [Python bindings for DeepStream](https://github.com/NVIDIA-AI-IOT/deepstream_python_apps). Make sure you have `pyds` available.

#### Allocations

When MetaData objects are allocated in Python, an allocation function is provided by the bindings to ensure proper memory ownership of the object. If the constructor is used, the the object will be claimed by the garbage collector when its Python references terminate. However, the object will still need to be accessed by C/C++ code downstream, and therefore must persist beyond those Python references.  

```python
import pyds_gkst

## to allocate 
obj = pyds_gkst.alloc_nvds_ppe_object()
obj = generate_ppe_meta(obj, class_id, lcStatus)

def generate_ppe_meta(data, class_id, lcStatus):
    obj = pyds_gkst.NvDsPPEObject.cast(data)
    obj.lcStatus = lcStatus[0]
    obj.direction = "south"
    obj.stream_id = "stream_id"
    obj.frame_unique_id = 'frame_unique_id'
    obj.frame = 'frame'
    obj.hasVest = 1
    obj.hasHelm = 0
    obj.full = 1    
    return obj
```