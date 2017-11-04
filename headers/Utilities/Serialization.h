/*
 * Serialization.h
 *
 *  Created on: 02/11/2017
 *      Author: jotaa
 */

#ifndef SRC_HEADERS_SERIALIZATION_H_
#define SRC_HEADERS_SERIALIZATION_H_

#include <vector>
#include <fstream>

using namespace std;

template<class Object>
class Serialization {

	void serialize(Object value, ofstream& ofs) {
		ofs << value << "\n";
	}

	void deserialize(Object value, ifstream& ifs) {
		ifs >> value;
	}

	void serializeVector(vector<Object> vec, ofstream& ofs) {
		for (size_t i = 0; i < vec.size(); i++) {
			ofs << vec.at(i) << "\n";
		}
	}

	void deserializeVector(vector<Object> vec, ifstream& ifs) {
		for (size_t i = 0; i < vec.size(); i++) {
			ifs >> vec.at(i);
		}
	}
};

#endif /* SRC_HEADERS_SERIALIZATION_H_ */
