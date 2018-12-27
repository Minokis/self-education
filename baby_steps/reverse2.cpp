vector<int> Reversed(vector<int>& input) {
    auto v = input;
    int temp;
    if (v.size() != 0) {
      for (int i = 0; i < v.size() / 2; ++i) {
          temp = v[i];
          v[i] = v[v.size()-i-1];
          v[v.size()-i-1] = temp;
      }
    }
    return v;
}
