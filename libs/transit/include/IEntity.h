#ifndef ENTITY_H_
#define ENTITY_H_

#include <vector>
#include <string>
#include "TripData.h"
#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

using namespace routing;

/**
 * @class IEntity
 * @brief Represents an entity in a physical system.
 *
 * An IEntity object has a unique ID, a position, a direction, a destination,
 * and details. It also has a speed, which determines how fast the entity moves
 * in the physical system. Subclasses of IEntity can override the `Update`
 * function to implement their own movement behavior.
 */
class IEntity {
 public:
  /**
   * @brief Constructor that assigns a unique ID to the entity.
   */
  IEntity() {
    static int currentId = 0;
    id = currentId;
    currentId++;
  }

  /**
   * @brief Virtual destructor for IEntity.
   */
  virtual ~IEntity() { delete graph; }

  /**
   * @brief Gets the ID of the entity.
   * @return The ID of the entity.
   */
  virtual int GetId() const { return id; }

  /**
   * @brief Gets the position of the entity.
   * @return The position of the entity.
   */
  virtual Vector3 GetPosition() const = 0;

  /**
   * @brief Gets the direction of the entity.
   * @return The direction of the entity.
   */
  virtual Vector3 GetDirection() const = 0;

  /**
   * @brief Gets the destination of the entity.
   * @return The destination of the entity.
   */
  virtual Vector3 GetDestination() const = 0;

  /**
   * @brief Gets the details of the entity.
   * @return The details of the entity.
   */
  virtual JsonObject GetDetails() const = 0;

  /**
   * @brief Gets the color of the drone
   * @return The color of the drone
   */
  virtual std::string GetColor() const { return "None"; }

  /**
   * @brief Gets the speed of the entity.
   * @return The speed of the entity.
   */
  virtual float GetSpeed() const = 0;

  /**
   * @brief Gets the availability of the entity.
   * @return The availability of the entity.
   */
  virtual bool GetAvailability() const { return false; }

  /**
   * @brief Get the Strategy Name
   *
   * @return string representing strategy name
   */
  virtual std::string GetStrategyName() const { return ""; }

  /**
   * @brief Get the pointer to the current trip data
   *
   * @return The pointer to the trip data
   */
  virtual TripData* GetTripData() { return nullptr; }

  /**
   * @brief Set the Strategy Name
   *
   * @param strategyName_ Strategy name
   */
  virtual void SetStrategyName(std::string strategyName_) {}

  /**
   * @brief Sets the availability of the entity.
   * @param choice The desired availability of the entity.
   */
  virtual void SetAvailability(bool choice) {}

  /**
   * @brief Updates the entity's position in the physical system.
   * @param dt The time step of the update.
   * @param scheduler The list of all entities in the system.
   */
  virtual void Update(double dt, std::vector<IEntity*> scheduler) {}

  /**
   * @brief Sets the graph object used by the entity in the simulation.
   * @param graph The IGraph object to be used.
   */
  virtual void SetGraph(const IGraph* graph) { this->graph = graph; }

  /**
   * @brief Sets the position of the entity.
   * @param pos_ The desired position of the entity.
   */
  virtual void SetPosition(Vector3 pos_) {}

  /**
   *@brief Set the direction of the entity.
   *@param dir_ The new direction of the entity.
   */
  virtual void SetDirection(Vector3 dir_) {}

  /**
   *@brief Set the destination of the entity.
   *@param des_ The new destination of the entity.
   */
  virtual void SetDestination(Vector3 des_) {}

  /**
   * @brief Sets the color of the drone
   * @param col_ The new color of the drone
   */
  virtual void SetColor(std::string col_) {}

  /**
   * @brief Sets the TripData pointed to for the current trip.
   * @param trip_ The TripData pointer
   */
  virtual void SetTripData(TripData* _trip) {}

  /**
   * @brief Rotate the entity.
   * @param angle The angle to rotate the entity by.
   */
  virtual void Rotate(double angle) {}

  /**
   * @brief Make the entity jump.
   * @param height The height to make the entity jump.
   */
  virtual void Jump(double height) {}

  /**
   * @brief Get a random float between given min and max
   * @param Min lower bound
   * @param Max upper bound
   * @return random float between given min and max
  */
  virtual float Random(float Min, float Max) {
    return ((static_cast<float>(rand()) /
    static_cast<float>(RAND_MAX)) * (Max - Min)) + Min;
  }

 protected:
  int id;
  const IGraph* graph;
};

#endif
