/*!
 * \file intFace.hpp
 * \brief Header file for the intFace class
 *
 * Class to handle calculation of interfce fluxes between all elements
 *
 * \author - Jacob Crabill
 *           Aerospace Computing Laboratory (ACL)
 *           Aero/Astro Department. Stanford University
 *
 * \version 0.0.1
 *
 * Flux Reconstruction in C++ (Flurry++) Code
 * Copyright (C) 2014 Jacob Crabill.
 *
 */
#pragma once

class face;

#include "face.hpp"

class intFace : public face
{
public:
  //! Setup arrays to handle getting/setting data at right element
  void setupRightState(void);

  //! Get data from the right element
  void getRightState(void);

  //! Put the calculated interface flux into the right element's memory
  void setRightState(void);

private:
  int locF_R;              //! Right element's local face ID
  int fptStartR, fptEndR;

  /* --- Storage for all solution/geometry data at flux points [right state] --- */
  vector<matrix<double>> FR;   //! Flux array [nFpts, nDims, nFields]
  vector<double*> FnR;    //! Common normal flux for right ele [in ele's memory]
  matrix<double> normR;   //! Unit outward normal at flux points  [nFpts, nDims]
  vector<double> dAR;     //! Local face-area equivalent at flux points
  vector<double> detJacR; //! Determinant of transformation Jacobian
};