#include <array>
#include <iostream>
#include <stddef.h>

template <typename T, size_t N = 5> class SmallVector {
public:
  explicit SmallVector(size_t size) : m_size(size) {
    if (size > N) {
      m_capacity = m_size;
      m_head = new T[m_capacity];

      std::cout << "construct heap memory" << std::endl;

    } else {
      m_capacity = N;
      m_head = m_data.data();

      std::cout << "construct stack memory" << std::endl;
    }
  }

  void push_back(const T &value) {

    if (m_size == m_capacity) {
      m_capacity *= 2;
      T *tmp = new T[m_capacity];
      std::copy_n(m_head, m_size, tmp);

      if (m_head != m_data.data()) {
        delete[] m_head;
      }

      m_head = tmp;

      std::cout << "reallocate memory on heap" << std::endl;
    }

    m_head[m_size++] = value;
  }

private:
  // heap memory
  T *m_head = nullptr;
  size_t m_size = 0;
  size_t m_capacity = N;
  // stack memory
  std::array<T, N> m_data;
};

int main() {

  SmallVector<int> v(0);

  for (int i = 0; i < 20; ++i) {
    v.push_back(i);
    std::cout << i << std::endl;
  }

  return 0;
}