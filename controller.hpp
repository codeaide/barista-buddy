/**
 * @brief Controller interface header file
 */
#ifndef BABU_CONTROLLER_INTERFACE_HEADER
#define BABU_CONTROLLER_INTERFACE_HEADER

namespace babu {
  
/**
 * @brief Controller interface
 */
class IController {
  public:
    /**
     * @brief Virtual destructor
     */
    virtual ~IController() { }

  private:
};

} // namespace babu

#endif /* BABU_CONTROLLER_INTERFACE_HEADER */
