#ifndef LOGGED_VARIABLE_REGISTRY_H_
#define LOGGED_VARIABLE_REGISTRY_H_

#include <vector>

// forward declare
template <typename T>
class LoggedVariable;

class LoggedVariableRegistry {
public:
  void registerInt(LoggedVariable<int> *variable);
  void registerDouble(LoggedVariable<double> *variable);

private:
  std::vector<LoggedVariable<int> *> ints;
  std::vector<LoggedVariable<double> *> doubles;
};

#endif // LOGGED_VARIABLE_REGISTRY_H_
