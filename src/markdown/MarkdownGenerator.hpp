#pragma once

#include "doxide.hpp"
#include "Entity.hpp"

/**
 * Markdown generator.
 */
class MarkdownGenerator {
public:
  /**
   * Generate documentation.
   * 
   * @param dir Output directory.
   * @param node Root node.
   */
  void generate(const std::filesystem::path& dir, const Entity& node);

private:
  void generateGroup(const std::filesystem::path& dir, const Entity& node);
  void generateMacro(const std::filesystem::path& dir, const Entity& node);
  void generateType(const std::filesystem::path& dir, const Entity& node);
  void generateVariable(const std::filesystem::path& dir, const Entity& node);

  template<class Iterator>
  void generateFunction(const std::filesystem::path& dir,
      const Iterator& first, const Iterator& last);

  template<class Iterator>
  void generateOperator(const std::filesystem::path& dir,
      const Iterator& first, const Iterator& last);

  /**
   * Process a documentation comment to detailed description.
   */
  static std::string detailed(const std::string& str);

  /**
   * Process a documentation comment to brief description.
   */
  static std::string brief(const std::string& str);

  /**
   * Process a documentation comment to a single line.
   */
  static std::string line(const std::string& str);

  /**
   * Indent the lines of a strong.
   */
  static std::string indent(const std::string& str);

  /**
   * Sanitize a string for HTML, replacing special characters with entities.
   */
  static std::string htmlize(const std::string& str);

  /**
   * Sanitize a string for a file name or internal anchor.
   */
  static std::string sanitize(const std::string& str);
};