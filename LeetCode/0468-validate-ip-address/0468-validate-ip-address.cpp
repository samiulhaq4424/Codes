class Solution {
public:
    string validIPAddress(string queryIP) {
        if (queryIP.find('.') != string::npos) {
            return isValidIPv4(queryIP) ? "IPv4" : "Neither";
        } else if (queryIP.find(':') != string::npos) {
            return isValidIPv6(queryIP) ? "IPv6" : "Neither";
        }
        return "Neither";
    }
    
private:
    bool isValidIPv4(string ip) {
        if (ip.empty() || ip.front() == '.' || ip.back() == '.') return false;
        
        vector<string> parts;
        string part;
        stringstream ss(ip);
        while (getline(ss, part, '.')) {
            parts.push_back(part);
        }
        
        if (parts.size() != 4) return false;
        
        for (string p : parts) {
            if (p.empty() || p.size() > 3 || (p.size() > 1 && p[0] == '0')) return false;
            for (char c : p) {
                if (!isdigit(c)) return false;
            }
            int num = stoi(p);
            if (num < 0 || num > 255) return false;
        }
        
        return true;
    }
    
    bool isValidIPv6(string ip) {
        if (ip.empty() || ip.front() == ':' || ip.back() == ':') return false;
        
        vector<string> parts;
        string part;
        stringstream ss(ip);
        while (getline(ss, part, ':')) {
            parts.push_back(part);
        }
        
        if (parts.size() != 8) return false;
        
        for (string p : parts) {
            if (p.empty() || p.size() > 4) return false;
            for (char c : p) {
                if (!isdigit(c) && !(('a' <= tolower(c) && tolower(c) <= 'f'))) return false;
            }
        }
        
        return true;
    }
};