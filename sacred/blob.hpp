#ifndef SACRED_BLOB_HPP_
#define SACRED_BLOB_HPP_

#include <vector>

#include "array.hpp"
#include "clipped_index_strategy.hpp"
#include "index_strategy.hpp"

namespace sacred {

  using std::vector;

  template <typename F>
  class Blob {
  public:
    Blob() = default;

    explicit Blob(const vector<int> &shape, IndexStrategy<F> &index_strategy = Array<F>::clipped_index_strategy)
        : value_(shape, index_strategy), diff_(shape, index_strategy) {}

    Blob(const vector<int> &shape, const vector<F> &value,
        IndexStrategy<F> &index_strategy = Array<F>::clipped_index_strategy)
        : value_(shape, value, index_strategy), diff_(shape, index_strategy) {}

    Blob(const vector<int> &shape, const vector<F> &value, const vector<F> &diff,
        IndexStrategy<F> &index_strategy = Array<F>::clipped_index_strategy)
        : value_(shape, value, index_strategy), diff_(shape, diff, index_strategy) {}

    ~Blob() = default;

    inline int count() const {
      return value_.count();
    }

    inline const Array<F> &diff() const {
      return diff_;
    }

    inline Array<F> &diff() {
      return diff_;
    }

    inline const F &diff(int index) const {
      return diff_.data(index);
    }

    inline F &diff(int index) {
      return diff_.data(index);
    }

    inline F diff(const vector<int> &indices) const {
      return diff_.at(indices);
    }

    inline int number_of_axes() const {
      return value_.number_of_axes();
    }

    inline const vector<int> &shape() const {
      return value_.shape();
    }

    inline int shape(int index) const {
      return value_.shape(index);
    }

    inline const Array<F> &value() const {
      return value_;
    }

    inline Array<F> &value() {
      return value_;
    }

    inline const F &value(int index) const {
      return value_.data(index);
    }

    inline F &value(int index) {
      return value_.data(index);
    }

    inline F value(const vector<int> &indices) const {
      return value_.at(indices);
    }

    void Reshape(const vector<int> &shape) {
      value_.Reshape(shape);
      diff_.Reshape(shape);
    }

  private:
    Array<F> value_, diff_;
  };

}  // namespace sacred

#endif  // SACRED_BLOB_HPP_
