#include "bind_string_property_definitions.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "pyds_gkst.h"
#include "nvdsmeta_schema.h"
//#include "custom_schema.h"

namespace py = pybind11;

PYBIND11_MODULE(pyds_gkst, m)
{

        py::class_<NvDsPPEObject>(m, "NvDsPPEObject", py::module_local())
            .def(py::init<>())
            .def_property("stream_id", STRING_PROPERTY(NvDsPPEObject, stream_id))
            .def_property("frame_unique_id", STRING_PROPERTY(NvDsPPEObject, frame_unique_id))
            .def_property("frame", STRING_PROPERTY(NvDsPPEObject, frame))
            .def_property("lcStatus", STRING_PROPERTY(NvDsPPEObject, lcStatus))
            .def_property("direction",STRING_PROPERTY(NvDsPPEObject, direction))
            .def_property("classId",STRING_PROPERTY(NvDsPPEObject, classId))
            .def_readwrite("hasVest",&NvDsPPEObject::hasVest)
            .def_readwrite("hasHelm",&NvDsPPEObject::hasHelm)
            .def_readwrite("full",&NvDsPPEObject::full)
            .def("cast",
                [](void *data) {
                        return (NvDsPPEObject *) data;
                },
                py::return_value_policy::reference)
            .def("cast",
                [](size_t data) {
                        return (NvDsPPEObject *) data;
                },
                py::return_value_policy::reference);

        m.def("alloc_nvds_ppe_object",              
              []() {
                  auto *object = (NvDsPPEObject *) g_malloc0(
                          sizeof(NvDsPPEObject));
                  return object;
              }, py::return_value_policy::reference);
}