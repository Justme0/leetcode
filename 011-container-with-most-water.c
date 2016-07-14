int maxArea(int *heights, int heightsSize) {
  int max_area = 0;
  int left = 0;
  int right = heightsSize - 1;
  while (left < right) {
    int new_area =
        (right - left) *
        (heights[left] < heights[right] ? heights[left] : heights[right]);
    if (new_area > max_area) {
      max_area = new_area;
    }

    // New area would be bigger than old area only if its height is bigger
    // than old less height.
    // optimize height[left] < height[right] ? ++left : --right;
    if (heights[left] <= heights[right]) {
      int old_height = heights[left];
      do {
        ++left;
      } while (heights[left] <= old_height && left < right);
    } else {
      int old_height = heights[right];
      do {
        --right;
      } while (heights[right] <= old_height && left < right);
    }
  }

  return max_area;
}
