#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
#include "json.hpp"
#include <cassert>
#include <cmath>
#include <fstream>
#include <ios>
#include <iostream>
#include <memory>

#include "Date.h"
#include "Location.h"
#include "LocationDateLength.h"

#define assert_with_message(condition, message)                                \
  if (!(condition)) {                                                          \
    assert((message, (condition)));                                            \
  }

/*
 * parse_json_daylength_response
 *
 * This function parses the JSON response from the Sunrise Sunset
 * Web API and replaces the length in the member of the first
 * parameter with the value embedded in the JSON.
 *
 * input: _raw_json_: The resulting data, as a std::string,
 *         of the Sunrise Sunset WebAPI call.
 * output: _day_length_response: A std::unique_ptr to a
 *         LocationDateLength struct whose length member is updated
 *         to match the daylength embedded in the 1st parameter.
 * return: A bool: true if the content downloaded from the Sunrise
 *         Sunset API was properly formatted; false otherwise.
 */
bool parse_json_daylength_response(std::string raw_json,
                                   LocationDateLength &day_length_response) {
  using nlohmann::json;
  try {
    auto parsed_json = json::parse(raw_json);
    auto iso_time{parsed_json["results"]["day_length"].get<int>()};

    day_length_response.setLength(iso_time);
    return true;
  } catch (json::parse_error &e) {
    /*
     * There was a parsing error.
     */
    return false;
  }
}

/*
 * download
 *
 * This function will use HTTP to connect to the server, issue the
 * Web API call and download the server's response. In the case of
 * an error, the function will return false. Otherwise, the function
 * will return true.
 *
 * input: _host_: The name of the server from which to download.
 *        _path_: The path of the Web API.
 * output: _content_: The content of the Web API call's response.
 * return: A bool: true if the Web API was properly invoked; false, otherwise.
 */
bool download(std::string host, std::string path, std::string &content) {
  auto client = httplib::Client(host);

  auto result = client.Get(path.c_str());

  if (result && result->status == 200) {
    content = result->body;
    return true;
  } else {
    return false;
  }
}

/*
 * build_url_path
 *
 * The function will use the values in the LocationDateLength
 * C++ struct given as a parameter to create a properly-formatted WebAPI
 * query for the Sunrise Sunset API. The struct must contain valid values
 * for the date and the location. The resulting std::string can be used
 * as an argument to the download function.
 *
 * input: _daylength_: The date and location for which to request the
 *        daylength from the Sunrise Sunset Web API.
 * return: A std::string that contains the properly-formatted path of the
 *         Sunrise Sunset WebAPI request for the given date and location.
 */
std::string build_url_path(LocationDateLength &daylength) {
  assert_with_message(
      daylength.getDate().getDay() > 0 && daylength.getDate().getDay() < 32 &&
          daylength.getDate().getYear() > 999 &&
          daylength.getDate().getYear() < 3000 &&
          daylength.getDate().getMonth() > 0 &&
          daylength.getDate().getMonth() < 12,
      std::string{"Date parameters in the argument appear to be invalid."});
  assert_with_message(
      std::abs(daylength.getLocation().getLatitude()) < 180.0 &&
          std::abs(daylength.getLocation().getLongitude()) < 180.0,
      std::string{"Location parameters in argument appear to be invalid."});

  std::stringstream url_path_stream{""};
  url_path_stream << "/json?formatted=0&lat="
                  << daylength.getLocation().getLatitude()
                  << "&lng=" << daylength.getLocation().getLongitude()
                  << "&date=" << daylength.getDate().getYear() << "-"
                  << daylength.getDate().getMonth() << "-"
                  << daylength.getDate().getDay();
  return url_path_stream.str();
}

int main() {
    int day, month, year;
    char dash;
    std::ifstream input{ "query_file.txt" };

    if (!input.is_open()) {
        std::cout << "Oops: Could not open file.\n";
        return 0;
    }

    if (!(input >> year)) {
        std::cout << "Oops: Could not read two valid dates from file.\n";
        return 0;
    }

    if (!(input >> dash)) {
        std::cout << "Oops: Could not read two valid dates from file.\n";
        return 0;
    }

    if (!(input >> month)) {
        std::cout << "Oops: Could not read two valid dates from file.\n";
        return 0;
    }

    if (!(input >> dash)) {
        std::cout << "Oops: Could not read two valid dates from file.\n";
        return 0;
    }

    if (!(input >> day)) {
        std::cout << "Oops: Could not read two valid dates from file.\n";
        return 0;
    }

    Date dateA{year, month, day};

    if (!(input >> year)) {
        std::cout << "Oops: Could not read two valid dates from file.\n";
        return 0;
    }

    if (!(input >> dash)) {
        std::cout << "Oops: Could not read two valid dates from file.\n";
        return 0;
    }

    if (!(input >> month)) {
        std::cout << "Oops: Could not read two valid dates from file.\n";
        return 0;
    }

    if (!(input >> dash)) {
        std::cout << "Oops: Could not read two valid dates from file.\n";
        return 0;
    }

    if (!(input >> day)) {
        std::cout << "Oops: Could not read two valid dates from file.\n";
        return 0;
    }

    Date dateB{year, month, day };

    Location locationA{};
    Location locationB{};

    locationA.setLatitude(39.103119);
    locationA.setLongitude(-84.512016);
    locationB.setLatitude(39.103119);
    locationB.setLongitude(-84.512016);

    LocationDateLength ldlA{ dateA, locationA};
    LocationDateLength ldlB{ dateB, locationB};

    std::string urlPathA = build_url_path(ldlA);
    std::string urlPathB = build_url_path(ldlB);

    std::string contentA;
    std::string contentB;

    bool resultA = download("https://api.sunrise-sunset.org", urlPathA, contentA);
    bool resultB = download("https://api.sunrise-sunset.org", urlPathB, contentB);

    if (resultA == false || resultB == false) {
        std::cout << "Oops: There was a Web API error.\n";
        return 0;
   }

    parse_json_daylength_response(contentA, ldlA);
    parse_json_daylength_response(contentB, ldlB);

    int diff = ldlB - ldlA;

    std::string longerShorter;

    if (diff < 0) {
        longerShorter = "shorter";
        diff = -diff;
    } else {
        longerShorter = "longer";
    }

    // convert
    int seconds = diff % 60;
    int minutes = ((diff - seconds) / 60) % 60;
    int hours = (diff - minutes * 60) / 3600;

    std::cout << dateB << " was " << hours << " hour(s), " << minutes << " minute(s) and " << seconds << " second(s) " << longerShorter << " than " << dateA << ".\n";

    return 0;
}
