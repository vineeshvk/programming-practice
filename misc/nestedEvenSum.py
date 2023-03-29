'''
Write a recursive function called nestedEvenSum. Return the sum of all even numbers in an object which may contain nested objects.

Examples

obj1 = {
  "outer": 2,
  "obj": {
    "inner": 2,
    "otherObj": {
      "superInner": 2,
      "notANumber": True,
      "alsoNotANumber": "yup"
    }
  }
}
 
obj2 = {
  "a": 2,
  "b": {"b": 2, "bb": {"b": 3, "bb": {"b": 2}}},
  "c": {"c": {"c": 2}, "cc": 'ball', "ccc": 5},
  "d": 1,
  "e": {"e": {"e": 2}, "ee": 'car'}
}
 
nestedEvenSum(obj1) # 6
nestedEvenSum(obj2) # 10

'''

from typing import Dict

obj1 = {
    "outer": 2,
    "obj": {
        "inner": 2,
        "otherObj": {
            "superInner": 2,
            "notANumber": True,
            "alsoNotANumber": "yup"
        }
    }
}

obj2 = {
    "a": 2,
    "b": {"b": 2, "bb": {"b": 3, "bb": {"b": 2}}},
    "c": {"c": {"c": 2}, "cc": 'ball', "ccc": 5},
    "d": 1,
    "e": {"e": {"e": 2}, "ee": 'car'}
}


def nestedEvenSum(obj: Dict) -> int:
    if(obj == {}):
        return 0

    sum = 0
    nested_values = {}

    for x in obj.values():
        if isinstance(x, int) and x % 2 == 0:
            sum += x
        elif isinstance(x, dict):
            nested_values = {**nested_values, **x}

    return sum + nestedEvenSum(nested_values)


print(nestedEvenSum(obj1))
print(nestedEvenSum(obj2))
