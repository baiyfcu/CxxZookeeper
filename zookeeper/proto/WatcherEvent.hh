// File generated by hadoop record compiler. Do not edit.

#ifndef WatcherEvent_HH_
#define WatcherEvent_HH_

#include "Efc.hh"
#include "../../jute/inc/ERecord.hh"
#include "../../jute/inc/EBinaryInputArchive.hh"
#include "../../jute/inc/EBinaryOutputArchive.hh"
#include "../../jute/inc/ECsvOutputArchive.hh"
#include "../data/Stat.hh"

namespace efc {
namespace ezk {

class WatcherEvent: public ERecord {
public:
	int type;
	int state;
	EString path;

	WatcherEvent() {
	}
	WatcherEvent(int type, int state, EString path) {
		this->type = type;
		this->state = state;
		this->path = path;
	}
	int getType() {
		return type;
	}
	void setType(int m_) {
		type = m_;
	}
	int getState() {
		return state;
	}
	void setState(int m_) {
		state = m_;
	}
	EString getPath() {
		return path;
	}
	void setPath(EString m_) {
		path = m_;
	}
	virtual void serialize(EOutputArchive* a_, const char* tag)
			THROWS(EIOException) {
		a_->startRecord(this, tag);
		a_->writeInt(type, "type");
		a_->writeInt(state, "state");
		a_->writeString(path, "path");
		a_->endRecord(this, tag);
	}
	virtual void deserialize(EInputArchive* a_, const char* tag)
			THROWS(EIOException) {
		a_->startRecord(tag);
		type = a_->readInt("type");
		state = a_->readInt("state");
		path = a_->readString("path");
		a_->endRecord(tag);
	}
	virtual EString toString() {
		try {
			EByteArrayOutputStream s;
			ECsvOutputArchive a_(&s);
			a_.startRecord(this, "");
			a_.writeInt(type, "type");
			a_.writeInt(state, "state");
			a_.writeString(path, "path");
			a_.endRecord(this, "");
			s.write('\0');
			return (char*) s.data();
		} catch (EThrowable& ex) {
			ex.printStackTrace();
		}
		return "ERROR";
	}
	void write(EDataOutput* out) THROWS(EIOException) {
		EBinaryOutputArchive archive(out);
		serialize(&archive, "");
	}
	void readFields(EDataInput* in) THROWS(EIOException) {
		EBinaryInputArchive archive(in);
		deserialize(&archive, "");
	}
	virtual int compareTo(EObject* peer_) THROWS(EClassCastException) {
		WatcherEvent* peer = dynamic_cast<WatcherEvent*>(peer_);
		if (!peer) {
			throw EClassCastException(__FILE__, __LINE__,
					"Comparing different types of records.");
		}
		int ret = 0;
		ret = (type == peer->type) ? 0 : ((type < peer->type) ? -1 : 1);
		if (ret != 0)
			return ret;
		ret = (state == peer->state) ? 0 : ((state < peer->state) ? -1 : 1);
		if (ret != 0)
			return ret;
		ret = path.compareTo(&peer->path);
		if (ret != 0)
			return ret;
		return ret;
	}
	virtual boolean equals(EObject* peer_) {
		WatcherEvent* peer = dynamic_cast<WatcherEvent*>(peer_);
		if (!peer) {
			return false;
		}
		if (peer_ == this) {
			return true;
		}
		boolean ret = false;
		ret = (type == peer->type);
		if (!ret)
			return ret;
		ret = (state == peer->state);
		if (!ret)
			return ret;
		ret = path.equals(&peer->path);
		if (!ret)
			return ret;
		return ret;
	}
	virtual int hashCode() {
		int result = 17;
		int ret;
		ret = (int) type;
		result = 37 * result + ret;
		ret = (int) state;
		result = 37 * result + ret;
		ret = path.hashCode();
		result = 37 * result + ret;
		return result;
	}
	static EString signature() {
		return "LWatcherEvent(iis)";
	}
};

} /* namespace ezk */
} /* namespace efc */
#endif /* WatcherEvent_HH_ */