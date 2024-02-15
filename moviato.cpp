#include <iostream>
#include <vector>
#include <algorithm>

struct Movie {
    std::string movieName;
    double rating = 0;
    std::string genre;
    double views = 0;
};

bool compareByName(const Movie& a, const Movie& b) {
    return a.movieName < b.movieName;
}

bool compareByRating(const Movie& a, const Movie& b) {
    return a.rating > b.rating;
}

bool compareByViews(const Movie& a, const Movie& b) {
    return a.views > b.views;
}

void printMovies(const std::vector<Movie>& movies) {
    for (const auto& movie : movies) {
        std::cout << "{ movieName: \"" << movie.movieName << "\", rating: " << movie.rating
                  << ", genre: \"" << movie.genre << "\", views: " << movie.views << " }\n";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<Movie> inputMovies = {
        {"Barbie", 4.5, "Comedy", 1.5},
        {"Interstellar", 3, "Fantastic", 4.5},
        {"The Godfather", 9.77, "Crime", 12.0}
    };

    std::sort(inputMovies.begin(), inputMovies.end(), compareByName);
    std::cout << "1. Sort by Movie Name:\n";
    printMovies(inputMovies);

    std::sort(inputMovies.begin(), inputMovies.end(), compareByRating);
    std::cout << "2. Sort by Rating:\n";
    printMovies(inputMovies);

    std::sort(inputMovies.begin(), inputMovies.end(), compareByName);
    std::cout << "3. Categorize by Genre:\n";
    std::string currentGenre = "";
    for (const auto& movie : inputMovies) {
        if (movie.genre != currentGenre) {
            currentGenre = movie.genre;
		}
          
        std::cout << "{ movieName: \"" << movie.movieName << "\", rating: " << movie.rating
                  << ", genre: \"" << movie.genre << "\", views: " << movie.views << " }\n";
    }

	std::cout << std::endl;
    std::sort(inputMovies.begin(), inputMovies.end(), compareByViews);
    std::cout << "4. Sort by Views:\n";
    printMovies(inputMovies);

    return 0;
}

