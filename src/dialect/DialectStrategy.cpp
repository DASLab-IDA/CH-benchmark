/*
Copyright 2014 Florian Wolf, SAP AG

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "DialectStrategy.h"
#include "MySqlDialect.h"
#include "HanaDialect.h"
#include "PostgresDialect.h"

Dialect* DialectStrategy::instance = 0;

Dialect* DialectStrategy::getInstance(){
if(instance == 0)
	//instance = new HanaDialect();
	//instance = new MySqlDialect();
	instance = new PostgresDialect();
	return instance;
}
