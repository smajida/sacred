#ifndef SACRED_INDEX_STRATEGY_HPP_
#define SACRED_INDEX_STRATEGY_HPP_

#include <vector>

namespace sacred {

using std::vector;

// TODO(robertsdionne): Promote tensor namespace to parent.
namespace tensor {

template <typename F>
class IndexStrategy {
public:
  virtual ~IndexStrategy() = default;

  virtual vector<int> Transform(const vector<int> &shape, const vector<int> &stride, const vector<int> &index) = 0;
};

}  // namespace tensor

// TODO(robertsdionne): Remove legacy IndexStrategy.
template <typename F>
class IndexStrategy {
public:
  virtual ~IndexStrategy() = default;

  virtual F Parity(const vector<int> &indices) const {
    return F(1.0);
  }

  virtual bool Resize() const {
    return true;
  };

  /**
   * Calculates the index of data given the data size, array shape and indices.
   * @param  data_size The size of the data buffer.
   * @param  shape     The shape of the tensor.
   * @param  indices   The indices into the tensor.
   * @return           The index into the data buffer corresponding to the given indices, or -1 if out of bounds.
   */
  virtual int Offset(int data_size, const vector<int> &shape, const vector<int> &indices) const = 0;
};

}  // namespace sacred


#endif  // SACRED_INDEX_STRATEGY_HPP_
