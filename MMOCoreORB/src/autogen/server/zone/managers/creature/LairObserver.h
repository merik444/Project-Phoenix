/*
 *	autogen/server/zone/managers/creature/LairObserver.h generated by engine3 IDL compiler 0.60
 */

#ifndef LAIROBSERVER_H_
#define LAIROBSERVER_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

#ifndef likely
#ifdef __GNUC__
#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)
#else
#define likely(x)       (x)
#define unlikely(x)     (x)
#endif
#endif
namespace server {
namespace zone {
namespace objects {
namespace creature {

class CreatureObject;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class TangibleObject;

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

namespace server {
namespace zone {
namespace managers {
namespace creature {

class HealLairObserverEvent;

} // namespace creature
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::creature;

#include "system/thread/atomic/AtomicInteger.h"

#include "engine/core/ManagedObject.h"

#include "engine/util/Observer.h"

#include "engine/util/Observable.h"

#include "server/zone/managers/creature/SpawnObserver.h"

namespace server {
namespace zone {
namespace managers {
namespace creature {

class LairObserver : public SpawnObserver {
public:
	LairObserver();

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void notifyDestruction(TangibleObject* lair, TangibleObject* attacker, int condition);

	bool checkForNewSpawns(TangibleObject* lair, TangibleObject* attacker, bool forceSpawn = false);

	void healLair(TangibleObject* lair, TangibleObject* attacker);

	void checkForHeal(TangibleObject* lair, TangibleObject* attacker, bool forceNewUpdate = false);

	void doAggro(TangibleObject* lair, TangibleObject* attacker, bool allAttack = false);

	bool isLairObserver();

	int getLivingCreatureCount();

	int getMobType();

	int getSpawnNumber();

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead() const;

	void _setImplementation(DistributedObjectServant* servant);

protected:
	LairObserver(DummyConstructorParameter* param);

	virtual ~LairObserver();

	friend class LairObserverHelper;
};

} // namespace creature
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::creature;

namespace server {
namespace zone {
namespace managers {
namespace creature {

class LairObserverImplementation : public SpawnObserverImplementation {
protected:
	AtomicInteger spawnNumber;

	Reference<HealLairObserverEvent* > healLairEvent;

public:
	LairObserverImplementation();

	LairObserverImplementation(DummyConstructorParameter* param);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void notifyDestruction(TangibleObject* lair, TangibleObject* attacker, int condition);

	virtual bool checkForNewSpawns(TangibleObject* lair, TangibleObject* attacker, bool forceSpawn = false);

	void healLair(TangibleObject* lair, TangibleObject* attacker);

	virtual void checkForHeal(TangibleObject* lair, TangibleObject* attacker, bool forceNewUpdate = false);

	void doAggro(TangibleObject* lair, TangibleObject* attacker, bool allAttack = false);

	bool isLairObserver();

	int getLivingCreatureCount();

	int getMobType();

	int getSpawnNumber();

	WeakReference<LairObserver*> _this;

	operator const LairObserver*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~LairObserverImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class LairObserver;
};

class LairObserverAdapter : public SpawnObserverAdapter {
public:
	LairObserverAdapter(LairObserver* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void notifyDestruction(TangibleObject* lair, TangibleObject* attacker, int condition);

	bool checkForNewSpawns(TangibleObject* lair, TangibleObject* attacker, bool forceSpawn);

	void healLair(TangibleObject* lair, TangibleObject* attacker);

	void checkForHeal(TangibleObject* lair, TangibleObject* attacker, bool forceNewUpdate);

	void doAggro(TangibleObject* lair, TangibleObject* attacker, bool allAttack);

	bool isLairObserver();

	int getLivingCreatureCount();

	int getMobType();

	int getSpawnNumber();

};

class LairObserverHelper : public DistributedObjectClassHelper, public Singleton<LairObserverHelper> {
	static LairObserverHelper* staticInitializer;

public:
	LairObserverHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<LairObserverHelper>;
};

} // namespace creature
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::creature;

#endif /*LAIROBSERVER_H_*/
