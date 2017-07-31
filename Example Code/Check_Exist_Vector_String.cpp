// example of searching vectors or strings

if(std::find(msg_allowed.begin(), msg_allowed.end(), msg[i]) != msg_allowed.end()) {
	} else {cout << "Character not allowed, try again." << endl; goto retry;}