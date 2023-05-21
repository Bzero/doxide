#pragma once

#include "doxide.hpp"

/**
 * Entity types.
 */
enum class EntityType {
  NONE,
  NAMESPACE,
  TYPE,
  VARIABLE,
  FUNCTION,
  OPERATOR,
  ENUMERATOR,
  MACRO,
  GROUP,
  FILE
};

/**
 * Entity.
 */
struct Entity {
  using map_type = std::map<std::string,Entity>;
  using multimap_type = std::multimap<std::string,Entity>;

  /**
   * Constructor.
  */
  Entity();

  /**
   * Add a child node.
   */
  void add(const Entity& node);

  /**
   * Get a namespace node, creating it if necessary.
   */
  Entity& ns(const std::string& name);

  /**
   * Get a group node, creating it if necessary.
   */
  Entity& group(const std::string& name);

  /**
   * Child namespaces.
   */
  map_type namespaces;

  /**
   * Child types.
   */
  map_type types;

  /**
   * Child variables.
   */
  map_type variables;

  /**
   * Child functions.
   */
  multimap_type functions;

  /**
   * Child operators.
   */
  multimap_type operators;

  /**
   * Child enumerators.
   */
  map_type enumerators;

  /**
   * Child macros.
   */
  map_type macros;

  /**
   * Child groups.
   */
  map_type groups;

  /**
   * Entity name (e.g. name of variable, function, class).
   */
  std::string name;

  /**
   * Entity declaration (e.g. function signature).
   */
  std::string decl;

  /**
   * Entity documentation.
   */
  std::string docs;

  /**
   * Alternative brief description.
   */
  std::string brief;

  /**
   * Group to which this belongs.
   */
  std::string ingroup;

  /**
   * Entity type.
   */
  EntityType type;

  /**
   * Hide this node?
   */
  bool hide;
};