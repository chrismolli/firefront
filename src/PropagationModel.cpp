/*

Copyright (C) 2012 ForeFire Team, SPE, Universit� de Corse.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 US

*/

#include "PropagationModel.h"
#include "DataBroker.h"

using namespace std;

namespace libforefire{

PropagationModel* getDefaultPropagationModel(const int & mindex, DataBroker* db) {
	return new PropagationModel(mindex, db);
}

PropagationModel::PropagationModel(const int & mindex, DataBroker* db)
: ForeFireModel(mindex, db) {
}

PropagationModel::~PropagationModel() {
}

double PropagationModel::getSpeedForNode(FireNode* fn){
	dataBroker->getPropagationData(this, fn);
	return getSpeed(properties);
}

}