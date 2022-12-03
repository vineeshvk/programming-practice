void main() {
  final match = MarkdownElement(text: "_**Hello**_");
  print(match.parseText());
  // print(match.debug());
  print(elements.map((e) => e.children));
  print(elements.map((e) => e.text));
}

List<MarkdownElement> elements = [];

class MarkdownParser {
  final String value;

  MarkdownParser(this.value);

  // void parse() {
  //   print(MarkdownElement(text: "**Hello**").parseText());
  // }
}

class MarkdownElement {
  MarkdownTag type;
  String text;
  List<MarkdownElement> children = [];

  MarkdownElement({this.type = MarkdownTag.none, this.text = ''});

  static final elementRegex = RegExp(r'{{(\d+)}}');

  @override
  String toString() {
    return "{{$hashCode}}";
  }

  String debug() {
    return "$text[${children.map((e) => e.debug())}]";
  }

  String parseText() {
    for (final tag in MarkdownTag.values) {
      if (tag == type || tag == MarkdownTag.none) continue;

      final matches = mdRegex[tag]!.allMatches(text);
      // print(matches);

      String resultString = "";
      int startIndex = 0;

      for (Match m in matches) {
        resultString += text.substring(startIndex, m.start);

        // String matchedText = text.substring(m.start, m.end);
        print([m.input, m.group(1)]);

        final markdownE = MarkdownElement.castWithChild(m.group(1)!, tag);
        if (markdownE != null) {
          resultString += markdownE.toString();
          addChild(markdownE);
          elements.add(markdownE);
        }
        startIndex = m.end;
      }

      resultString += text.substring(startIndex);
      text = resultString;
      // print("string $text");
    }

    return text;
  }

  static MarkdownElement? castWithChild(String processedText, MarkdownTag tag) {
    if (processedText.isEmpty) return null;

    final matches = elementRegex.allMatches(processedText);
    if (matches.isEmpty) return MarkdownElement(type: tag, text: processedText);

    String resultText = "";
    int startIndex = 0;

    for (Match m in matches) {
      resultText += processedText.substring(startIndex, m.start);

      // String matchedText = processedText.substring(m.start, m.end);
      final markdownE = MarkdownElement(type: tag, text: m.group(1)!);
      final e = elements.firstWhere(
        (element) => element.hashCode == int.parse(m.group(1)!),
      );
      markdownE.addChild(e);
      print("regex ${m.group(1)} ${markdownE.children} ${markdownE.hashCode}");
      resultText += markdownE.toString();

      elements.add(markdownE);
      print("regex2 ${elements.map((e) => e.children)}");
      startIndex = m.end;
    }

    resultText += processedText.substring(startIndex);
    return MarkdownElement(type: tag, text: resultText);
  }

  void addChild(MarkdownElement child) {
    children.add(child);
  }
}

enum MarkdownTag { b, i, none }

const String _baseCharacters = r'a-zA-Z0-9\/?.",!:<>' r"'{}";
final mdRegex = {
  MarkdownTag.b: RegExp(r'\*{2}([' + _baseCharacters + r'_~`\-\s]*)\*{2}'),
  MarkdownTag.i: RegExp(r'_([' + _baseCharacters + r'_~`\-\s]*)_'),
};
