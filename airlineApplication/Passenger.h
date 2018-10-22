/* W04
 * Passenger.h
 * Ivy Leano
 */

#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
#define MAXLENGTH 19

namespace sict 
{
	class Passenger 
	{
	private:

		char passName[MAXLENGTH];
		char destin[MAXLENGTH];
		int yearDepart;
		int monthDepart;
		int dayDepart;

	public:

		Passenger();
		Passenger(const char * passengerName, const char * destination);
		Passenger(const char * passengerName, const char * destination, int yearDepart, int monthDepart, int dayDepart);

		const char* name() const;
		bool canTravelWith(const Passenger& passenger) const;
		bool isEmpty() const;
		void display() const;
	};
}
#endif // !SICT_PASSENGER_H