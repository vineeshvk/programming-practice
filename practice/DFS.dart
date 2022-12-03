void main() {
  final Map<int, List<int>> data = {
    0: [1, 2],
    1: [0, 5],
    2: [0],
    3: [6],
    4: [],
    5: [1],
    6: [3]
  };

  List<int> visitedNodes = [];
  List<int> stack = [];
  List<List<int>> friends = [];

  int i = 0;
  int val = i;
  friends.add([]);

  while (visitedNodes.length < data.keys.length) {
    print(visitedNodes);
    if (!visitedNodes.contains(val)) {
      visitedNodes.add(val);
      stack.add(val);

      val = data[val]!.first;
      if (val == null && stack.isNotEmpty) {
        val = stack.removeAt(stack.length - 1);
        friends.last.add(val);
      }
    }
    if (stack.isEmpty && val == null) {
      friends.add([]);
    }
  }

  print(visitedNodes);
}
