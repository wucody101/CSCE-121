#include <stdexcept>
#include <iostream>

int Largest(int a, int b, int c) {
  int d = a;
  if (b > d) {
    d = b;
  }
  if (c > d) {
    d = c;
  }
  return d;
}

bool SumIsEven(int a, int b) {
  if((a+b) % 2 != 0){
    return false;
  }
  else{
    return true;
  }
}

int BoxesNeeded(int apples) {
  if (apples <= 0) {
    return 0;
  }
  if (apples % 20 == 0) {
    return apples / 20;
  }
  return 1 + apples/20;
}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {
    if (A_correct < 0 || A_total <= 0 || B_correct < 0 || B_total <= 0 || A_correct > A_total || B_correct > B_total) {
      throw std::invalid_argument("Arguments are invalid");
    }
    if (static_cast<double>(A_correct)/A_total > static_cast<double>(B_correct)/B_total) {
      return true;
    }
    return false;
}

bool GoodDinner(int pizzas, bool is_weekend) {
  if (pizzas >= 10 && pizzas <= 20) {
    return true;
  }
  if (is_weekend && pizzas >= 10) {
    return true;
  }
  return false;
}

int SumBetween(int low, int high) {
  /*std::cout << low << std::endl;
  std::cout << high << std::endl;*/
  int value = 0;
  if (low > high) {
    throw std::invalid_argument("Low and High are out of order");
  }
  if (low == high) {
    return high;
  }
  if (low == -high) {
    return 0;
  }
  if (high + low > 0 && high > 0 && low < 0) {
    if (abs(low) + 1 == INT32_MAX) {
      return INT32_MAX;
    }
    for (int n = abs(low) + 1; n <= high; n++) {
      if (n > (INT32_MAX - value) && n > 0 && value > 0) {
        throw std::overflow_error("Overflow 1");
      }
      else if (n > (INT32_MAX + value) && n > 0 && value < 0) {
        throw std::overflow_error("Overflow 2");
      }
      else if (n < (INT32_MIN + value) && n < 0 && value > 0) {
        std::cout << n << " " << value;
        throw std::overflow_error("Overflow 3");
      }
      else if (n < (INT32_MIN - value) && n < 0 && value < 0) {
        throw std::overflow_error("Overflow 4");
      }
      else {
        value += n;
      }
    }
  }
  else if (high + low < 0 && high > 0 && low < 0) {
    for (int n = low; n < -high; n++) {
      if (n > (INT32_MAX - value) && n > 0 && value > 0) {
        throw std::overflow_error("Overflow 11");
      }
      else if (n > (INT32_MAX + value) && n > 0 && value < 0) {
        throw std::overflow_error("Overflow 21");
      }
      else if (n < (INT32_MIN + value) && n < 0 && value > 0) {
        throw std::overflow_error("Overflow 31");
      }
      else if (n < (INT32_MIN - value) && n < 0 && value < 0) {
        throw std::overflow_error("Overflow 41");
      }
      else {
        value += n;
      }
    }
  }
  else {
      for (int n = low; n <= high; n++) {
        if (n > (INT32_MAX - value) && n > 0 && value > 0) {
          throw std::overflow_error("Overflow 12");
        }
        else if (n > (INT32_MAX + value) && n > 0 && value < 0) {
          throw std::overflow_error("Overflow 22");
        }
        else if (n < (INT32_MIN + value) && n < 0 && value > 0) {
          throw std::overflow_error("Overflow 32");
        }
        else if (n < (INT32_MIN - value) && n < 0 && value < 0) {
          throw std::overflow_error("Overflow 42");
        }
        else {
          value += n;
        }
      }
  }
  return value;
}

int Product(int a, int b) {
  /*std::cout << a << std::endl;
  std::cout << b << std::endl;*/
  if (a == 0 || b == 0) {
    return a * b;
  }
  if ((a == -1 && b == INT32_MIN) || (a == INT32_MIN && b == -1)) {
    throw std::overflow_error("Overflow 9");
  }
  if (a > INT32_MAX / b && a > 0 && b > 0) {
    throw std::overflow_error("Overflow 5");
  }
  else if (a < INT32_MIN / b && a < 0 && b > 0) {
    throw std::overflow_error("Overflow 6");
  }
  else if (b < INT32_MIN / a && a > 0 && b < 0) {
    throw std::overflow_error("Overflow 7");
  }
  else if (a < INT32_MAX / b && a < 0 && b < 0) {
    throw std::overflow_error("Overflow 8");
  }
  else {
    return a * b;
  }
}
