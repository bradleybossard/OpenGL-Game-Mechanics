#ifndef COLOR_H
#define COLOR_H

#include <vector>

namespace GL {
  class Color {
    public:
      Color(int r = 0, int g = 0, int b = 0, int a = 255);
      int getR();
      int getG();
      int getB();
      int getA();

      std::vector<int> getRGBA();

    private:
      std::vector<int> _rgba;
  };
}

#endif
