#ifndef SACRED_IDENTITY_LOOKUP_HPP_
#define SACRED_IDENTITY_LOOKUP_HPP_

#include "default_types.hpp"
#include "lookup_strategy.hpp"

namespace sacred {

  template <typename I = default_integer_type>
  class IdentityLookup : public tensor::LookupStrategy<I> {
  public:
    using index_type = typename default_index_type<I>::value;

    IdentityLookup() = default;

    virtual I Offset(
        I data_size, const index_type &shape, const index_type &stride, const index_type &index) const override {
      auto result = I(0);
      for (auto i = I(0); i < stride.size(); ++i) {
        result += index.at(i) * stride.at(i);
      }
      return result;
    }
  };

}  // namespace sacred

#endif  // SACRED_IDENTITY_LOOKUP_HPP_
