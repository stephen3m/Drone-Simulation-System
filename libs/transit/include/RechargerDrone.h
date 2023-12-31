#ifndef RECHARGERDRONE_H_
#define RECHARGERDRONE_H_

#include <vector>

#include "DijkstraStrategy.h"
#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief Represents a Recharger drone in a physical system. Drones move using euler
 * integration based on a specified velocity and direction.
 **/
class RechargerDrone : public IEntity {
 public:
  /**
   * @brief Recharger Drones are created with a name
   * @param obj JSON object containing the drone's information
   */
  explicit RechargerDrone(JsonObject& obj);

  /**
   * @brief Destructor
   */
  ~RechargerDrone();

  /**
   * @brief Gets the speed of the Recharger drone
   * @return The speed of the Recharger drone
   */
  float GetSpeed() const override { return speed; }

  /**
   * @brief Gets the position of the Recharger drone
   * @return The position of the Recharger drone
   */
  Vector3 GetPosition() const override { return position; }

  /**
   * @brief Gets the direction of the Recharger drone
   * @return The direction of the Recharger drone
   */
  Vector3 GetDirection() const override { return direction; }

  /**
   * @brief Gets the destination of the Recharger drone
   * @return The destination of the Recharger drone
   */
  Vector3 GetDestination() const override { return destination; }

  /**
   * @brief Gets the details information of the Recharger drone
   * @return The details information of the Recharger drone
   */
  JsonObject GetDetails() const override { return details; }

  /**
   * @brief Gets the availability of the Recharger drone
   * @return The availability of the Recharger drone
   */
  bool GetAvailability() const override { return available; }

  /**
   * @brief Gets the boolean for if drone has been finished recharing
   * @return Boolean value for finishedRechargingDrone
   */
  bool GetFinishedRechargingDrone() const { return finishedRechargingDrone; }

  /**
   * @brief Updates the Recharger drone's position
   * @param dt Delta time
   * @param scheduler Vector containing all the entities in the system
   */
  void Update(double dt, std::vector<IEntity*> scheduler) override;

  /**
   * @brief Sets the position of the Recharger drone
   * @param pos_ The new position of the Recharger drone
   */
  void SetPosition(Vector3 pos_) override { position = pos_; }

  /**
   * @brief Sets the direction of the Recharger drone
   * @param dir_ The new direction of the Recharger drone
   */
  void SetDirection(Vector3 dir_) override { direction = dir_; }

  /**
   * @brief Sets the destination of the Recharger drone
   * @param des_ The new destination of the Recharger drone
   */
  void SetDestination(Vector3 des_) override { destination = des_; }

  /**
   * @brief Sets the droneToRecharge variable to drone pointer, destination
   * variable to drone position, and available variable to false
   * @param droneToRecharge The drone to recharge
   */
  void SetDroneToRecharge(IEntity* droneToRecharge);

  /**
   * @brief Recharges out-of-battery drone
   * @param dt Delta time
   */
  void RechargeDrone(double dt);

  /**
   * @brief Removing the copy constructor 
   * so that Recharger drones cannot be copied.
   */
  RechargerDrone(const RechargerDrone& drone) = delete;
  /**
   * @brief Removing the assignment operator
   * so that Recharger drones cannot be copied.
   */
  RechargerDrone& operator=(const RechargerDrone& drone) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  bool finishedRechargingDrone;
  IEntity* droneToRecharge = nullptr;
  IStrategy* routingStrategy = nullptr;
};

#endif
