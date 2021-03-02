#ifndef __TYPES_H__
#define __TYPES_H__

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include <vector>
#include <iostream>


namespace pyopengv {

namespace py = pybind11;

typedef py::array_t<double, py::array::c_style | py::array::forcecast> pyarray_d;

template <typename T>
py::array_t<T> py_array_from_data(const T *data, size_t shape0) {
  py::array_t<T> res({shape0});
  std::copy(data, data + shape0, res.mutable_data());
  return res;
}

template <typename T>
py::array_t<T> py_array_from_data(const T *data, size_t shape0, size_t shape1) {
  py::array_t<T> res({shape0, shape1});
  std::copy(data, data + shape0 * shape1, res.mutable_data());
  return res;
}

template <typename T>
py::array_t<T> py_array_from_vector(const std::vector<T> &v) {
  const T *data = v.size() ? &v[0] : NULL;
  return py_array_from_data(data, v.size());
}


double py_array_get(const pyarray_d &arr, size_t i) {
    return arr.data()[i];
}


double py_array_get(const pyarray_d &arr, size_t i, size_t j) {
    return arr.data()[i * arr.shape(1) + j];
}


double py_array_get2D(const pyarray_d &arr, size_t i, size_t j) {
    return arr.data()[i * arr.shape(1) * arr.shape(2) + j];
}
}

#endif // __TYPES_H__
