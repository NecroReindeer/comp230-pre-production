#include "stdafx.h"
#include "InitialisationError.h"


InitialisationError::InitialisationError(const std::string& message, const char* error)
{
	// Append error message to the message passed in
  errorMessage = message + "\n" + error;
}

