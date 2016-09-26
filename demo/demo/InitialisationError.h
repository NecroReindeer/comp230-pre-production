//! Class for initialisation errors.
/*!
This is a class for handling initialisation errors.
It inherits from the std::exception class.
*/

#pragma once

class InitialisationError : std::exception
{
public:
  //! Constructor for the error.
  /*!
  This is the constructor for the class. The error message
  should be passed in when the class is constructed.
  */
  InitialisationError(const std::string& message, const char* error);

  //! Return a pointer to the stored error message.
  /*!
  This returns the stored error message.
  */
  const char* what() { return errorMessage.c_str(); }

private:
  //! Private member to store error message.
  /*!
  This variable stores the error message that will be
  displayed as a std::string.
  */
  std::string errorMessage;
};

