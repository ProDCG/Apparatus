namespace app {
    template <typename T>
    T mat3<T>::det() const {
        return n11 * ((n22 * n33) - (n32 * n23)) - n12 * ((n21 * n33) - (n31 * n23)) + n13 * ((n21 * n32) - (n31 * n22));
    }
}