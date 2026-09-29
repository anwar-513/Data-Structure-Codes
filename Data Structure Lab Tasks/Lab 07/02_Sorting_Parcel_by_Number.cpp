#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

// A parcel is just (id, priority)
typedef pair<string, int> Parcel;

void printParcels(const vector<Parcel>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << "(" << v[i].first << "," << v[i].second << ")";
        if (i + 1 < v.size()) cout << " ";
    }
    cout << "]\n";
}

// Bubble sort with early exit and shrinking range.
// Stable: swaps only if the left priority is strictly greater.
// Results are returned through the reference parameters.
void bubbleSort(vector<Parcel>& a, long& comparisons, long& swaps, int& passes,
                bool verbose = false) {
    comparisons = 0;
    swaps = 0;
    passes = 0;
    int n = static_cast<int>(a.size());

    for (int pass = 0; pass < n - 1; ++pass) {
        bool swapped = false;
        // Last `pass` elements are already in place, so shrink the range.
        for (int i = 0; i < n - 1 - pass; ++i) {
            ++comparisons;
            if (a[i].second > a[i + 1].second) {
                swap(a[i], a[i + 1]);
                ++swaps;
                swapped = true;
            }
        }
        ++passes;
        if (verbose) {
            cout << "After pass " << passes << ": ";
            printParcels(a);
        }
        if (!swapped) break;  // early exit
    }
}

// Bonus: cocktail shaker sort (bidirectional bubble sort).
void cocktailSort(vector<Parcel>& a, long& comparisons, long& swaps, int& passes) {
    comparisons = 0;
    swaps = 0;
    passes = 0;
    int start = 0, end = static_cast<int>(a.size()) - 1;
    bool swapped = true;

    while (swapped && start < end) {
        swapped = false;

        // Forward pass: push the largest to the end.
        for (int i = start; i < end; ++i) {
            ++comparisons;
            if (a[i].second > a[i + 1].second) {
                swap(a[i], a[i + 1]);
                ++swaps;
                swapped = true;
            }
        }
        ++passes;
        if (!swapped) break;
        --end;

        swapped = false;
        // Backward pass: push the smallest to the start.
        for (int i = end; i > start; --i) {
            ++comparisons;
            if (a[i - 1].second > a[i].second) {
                swap(a[i - 1], a[i]);
                ++swaps;
                swapped = true;
            }
        }
        ++passes;
        ++start;
    }
}

// Ids of all parcels with the given priority, in the order they appear.
vector<string> idsWithPriority(const vector<Parcel>& v, int prio) {
    vector<string> ids;
    for (size_t i = 0; i < v.size(); ++i)
        if (v[i].second == prio) ids.push_back(v[i].first);
    return ids;
}

// Checks that parcels with equal priority keep their original relative order.
bool isStable(const vector<Parcel>& original, const vector<Parcel>& sorted) {
    for (size_t i = 0; i < original.size(); ++i) {
        int prio = original[i].second;
        if (idsWithPriority(original, prio) != idsWithPriority(sorted, prio))
            return false;
    }
    return true;
}

void printStats(const string& label, long comparisons, long swaps, int passes) {
    cout << label << ": passes=" << passes
         << ", comparisons=" << comparisons
         << ", swaps=" << swaps << "\n";
}

int main() {
    vector<Parcel> parcels;
    parcels.push_back(make_pair("P1", 4));
    parcels.push_back(make_pair("P2", 2));
    parcels.push_back(make_pair("P3", 4));
    parcels.push_back(make_pair("P4", 1));
    parcels.push_back(make_pair("P5", 3));
    parcels.push_back(make_pair("P6", 2));
    parcels.push_back(make_pair("P7", 5));
    parcels.push_back(make_pair("P8", 1));
    parcels.push_back(make_pair("P9", 3));
    parcels.push_back(make_pair("P10", 2));
    int n = static_cast<int>(parcels.size());

    long comps, swps;
    int passes;

    // Part 1 & 2: sort and trace
    cout << "=== Original ===\n";
    printParcels(parcels);

    cout << "\n=== Bubble Sort Trace ===\n";
    vector<Parcel> sortedParcels = parcels;
    bubbleSort(sortedParcels, comps, swps, passes, true);
    long bubbleComps = comps, bubbleSwps = swps;
    int bubblePasses = passes;

    cout << "\n=== Result ===\n";
    printParcels(sortedParcels);
    printStats("Bubble sort", bubbleComps, bubbleSwps, bubblePasses);
    cout << "Stable? " << (isStable(parcels, sortedParcels) ? "YES" : "NO") << "\n";

    // Part 3: analysis
    long worstCaseComparisons = static_cast<long>(n) * (n - 1) / 2;
    cout << "\n=== Analysis ===\n";
    cout << "Theoretical max comparisons n(n-1)/2 = " << worstCaseComparisons << "\n";
    cout << "Actual comparisons = " << bubbleComps << "\n";
    cout << "(Lower because early exit stops once a pass makes no swaps.)\n";

    // Best case: already sorted. Worst case: reverse sorted (all distinct priorities).
    vector<Parcel> best, worst;
    for (int i = 1; i <= n; ++i) best.push_back(make_pair("P" + to_string(i), i));
    for (int i = 1; i <= n; ++i) worst.push_back(make_pair("P" + to_string(i), n - i + 1));

    cout << "\n";
    bubbleSort(best, comps, swps, passes);
    printStats("Best case  (sorted)        ", comps, swps, passes);
    bubbleSort(worst, comps, swps, passes);
    printStats("Worst case (reverse sorted)", comps, swps, passes);

    // Bonus: cocktail shaker sort
    cout << "\n=== Bonus: Cocktail Shaker Sort ===\n";
    vector<Parcel> cockParcels = parcels;
    cocktailSort(cockParcels, comps, swps, passes);
    printParcels(cockParcels);
    printStats("Cocktail (original) ", comps, swps, passes);
    printStats("Bubble   (original) ", bubbleComps, bubbleSwps, bubblePasses);
    cout << "Stable? " << (isStable(parcels, cockParcels) ? "YES" : "NO") << "\n";

    // Where cocktail wins by the most: the smallest element sits at the far end.
    // Bubble moves it left only ONE step per pass; cocktail moves it all the way in one backward pass.
    vector<Parcel> turtle, turtle2;
    for (int i = 2; i <= n; ++i) turtle.push_back(make_pair("P" + to_string(i - 1), i));
    turtle.push_back(make_pair("P" + to_string(n), 1));
    turtle2 = turtle;

    cout << "\nTurtle input (small value at the end):\n";
    bubbleSort(turtle, comps, swps, passes);
    printStats("Bubble  ", comps, swps, passes);
    cocktailSort(turtle2, comps, swps, passes);
    printStats("Cocktail", comps, swps, passes);

    return 0;
}