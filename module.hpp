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
     * @brief Method to initialize the module
     * 
     * Override this method in your module to add initialization code
     * 
     * @return True when initialized successfully, False otherwise
     */
    bool init() {
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
    bool process() {
      Serial.println("Default processing called for \"" + m_strName + "\"");
      return true;
    }
    
  private:
    // module name
    String m_strName;
};

} // namespace babu

#endif /* BABU_BASE_MODULE_HEADER */
