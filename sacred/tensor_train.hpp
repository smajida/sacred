#ifndef SACRED_TENSOR_TRAIN_HPP_
#define SACRED_TENSOR_TRAIN_HPP_

#include "checked_index.hpp"
#include "default_types.hpp"
#include "functional.hpp"
#include "identity_lookup.hpp"
#include "index_strategy.hpp"
#include "lookup_strategy.hpp"
#include "tensor_interface.hpp"
#include "tensor.hpp"
#include "wrapped_index.hpp"

namespace sacred {

template <typename F = default_floating_point_type, typename I = default_integer_type>
class TensorTrain : public TensorInterface<F, I> {
public:
  using storage_type = typename default_storage_type<F>::value;
  using index_type = typename default_index_type<I>::value;
  using tensor_type = Tensor<F, I>;

  TensorTrain() = default;

  virtual ~TensorTrain() = default;

  template <typename Index = CheckedIndex<I>, typename Lookup = IdentityLookup<F, I>>
  tensor_type at(const index_type &index) {
    static_assert(is_base_of<tensor::IndexStrategy<I>, Index>::value,
        "Index must implement interface IndexStrategy<I>.");
    static_assert(is_base_of<tensor::LookupStrategy<F, I>, Lookup>::value,
        "Lookup must implement interface LookupStrategy<F, I>.");
    return F(0);
  }

  virtual operator F() const override {
    CHECK_STATE(1 == ProductOf(shape_));
    return F(0);
  }

  virtual const I number_of_axes() const override {
    return shape_.size();
  }

  virtual tensor_type operator [](const index_type &index) override {
    return at<WrappedIndex<I>, IdentityLookup<F, I>>(index);
  }

  virtual void operator =(F other) override {
  }

  virtual void operator =(const tensor_type &other) override {
  }

  virtual bool operator ==(const tensor_type &other) const override {
    return false;
  }

  virtual const index_type &shape() const override {
    return shape_;
  }

  virtual I size() const override {
    return 0;
  }

private:
  index_type shape_;
};

}  // namespace sacred

#endif  // SACRED_TENSOR_TRAIN_HPP_