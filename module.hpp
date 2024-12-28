/**
 * @brief Base module header file
 */
#ifndef BABU_BASE_MODULE_HEADER
#define BABU_BASE_MODULE_HEADER

#include <Arduino.h>

namespace babu {

/**
 * @brief Sensor interface
 */
class BaseModule {
  public:
    /**
     * @brief Virtual destructor
     */
    BaseModule(String strName) : m_strName(strName) { }

    /**
     * @brief Virtual destructor
     */
    virtual ~BaseModule() { }

    /**
     * @brief Method to get the module name
     *
     * @return Name of the module
     */
    virtual String getName() {
      return m_strName;
    }

    /**
     * @brief Method to initialize the module
     *
     * Override this method in your module to add initialization code
     *
     * @return True when initialized successfully, False otherwise
     */
    virtual bool init() {
      Serial.println("Default initialization called for \"" + m_strName + "\"");
      return true;
    }

    /**
     * @brief Method to process the module
     *
     * Override this method in your module to add processing code
     *
     * @return True when processed successfully, False otherwise
     */
    virtual bool process() {
      return true;
    }

  private:
    // module name
    String m_strName;
};

} // namespace babu

#endif /* BABU_BASE_MODULE_HEADER */
