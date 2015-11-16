#ifndef _VECTOR_
#define _VECTOR_

/*! \brief Represents a mathematical vector.
 *  \details Provides a full implementation of a mathematical vector, with 
 *  informations about the projections in both axes (components),
 *  the norm and so on.
 *  \date 12/09/2015
 *  \author Vitor Greati
 *  \version 1.0
 */
class MathVector {
	public:
		double horizontal;	/*!< Horizontal component's norm (x axis) */
		double vertical;	/*!< Vertical component's norm (y axis) */
		
		/*! \brief Calculates vector's norm.
		 *  \details A norm of a vector is the positive value that
		 *  that represents the size of the vector, counting both
		 *  components.
		 * \return Vector's norm.
		 */
		double size() const;

};

#endif
