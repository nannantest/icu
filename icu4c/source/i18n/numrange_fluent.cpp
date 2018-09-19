// © 2018 and later: Unicode, Inc. and others.
// License & terms of use: http://www.unicode.org/copyright.html

#include "unicode/utypes.h"

#if !UCONFIG_NO_FORMATTING

// Allow implicit conversion from char16_t* to UnicodeString for this file:
// Helpful in toString methods and elsewhere.
#define UNISTR_FROM_STRING_EXPLICIT

#include "numrange_impl.h"
#include "util.h"
#include "number_utypes.h"

using namespace icu;
using namespace icu::number;
using namespace icu::number::impl;


// This function needs to be declared in this namespace so it can be friended.
// NOTE: In Java, this logic is handled in the resolve() function.
void icu::number::impl::touchRangeLocales(RangeMacroProps& macros) {
    macros.formatter1.fMacros.locale = macros.locale;
    macros.formatter2.fMacros.locale = macros.locale;
}


template<typename Derived>
Derived NumberRangeFormatterSettings<Derived>::numberFormatterBoth(const UnlocalizedNumberFormatter& formatter) const& {
    Derived copy(*this);
    copy.fMacros.formatter1 = formatter;
    copy.fMacros.singleFormatter = true;
    touchRangeLocales(copy.fMacros);
    return copy;
}

template<typename Derived>
Derived NumberRangeFormatterSettings<Derived>::numberFormatterBoth(const UnlocalizedNumberFormatter& formatter) && {
    Derived move(std::move(*this));
    move.fMacros.formatter1 = formatter;
    move.fMacros.singleFormatter = true;
    touchRangeLocales(move.fMacros);
    return move;
}

template<typename Derived>
Derived NumberRangeFormatterSettings<Derived>::numberFormatterBoth(UnlocalizedNumberFormatter&& formatter) const& {
    Derived copy(*this);
    copy.fMacros.formatter1 = std::move(formatter);
    copy.fMacros.singleFormatter = true;
    touchRangeLocales(copy.fMacros);
    return copy;
}

template<typename Derived>
Derived NumberRangeFormatterSettings<Derived>::numberFormatterBoth(UnlocalizedNumberFormatter&& formatter) && {
    Derived move(std::move(*this));
    move.fMacros.formatter1 = std::move(formatter);
    move.fMacros.singleFormatter = true;
    touchRangeLocales(move.fMacros);
    return move;
}

template<typename Derived>
Derived NumberRangeFormatterSettings<Derived>::numberFormatterFirst(const UnlocalizedNumberFormatter& formatter) const& {
    Derived copy(*this);
    copy.fMacros.formatter1 = formatter;
    copy.fMacros.singleFormatter = false;
    touchRangeLocales(copy.fMacros);
    return copy;
}

template<typename Derived>
Derived NumberRangeFormatterSettings<Derived>::numberFormatterFirst(const UnlocalizedNumberFormatter& formatter) && {
    Derived move(std::move(*this));
    move.fMacros.formatter1 = formatter;
    move.fMacros.singleFormatter = false;
    touchRangeLocales(move.fMacros);
    return move;
}

template<typename Derived>
Derived NumberRangeFormatterSettings<Derived>::numberFormatterFirst(UnlocalizedNumberFormatter&& formatter) const& {
    Derived copy(*this);
    copy.fMacros.formatter1 = std::move(formatter);
    copy.fMacros.singleFormatter = false;
    touchRangeLocales(copy.fMacros);
    return copy;
}

template<typename Derived>
Derived NumberRangeFormatterSettings<Derived>::numberFormatterFirst(UnlocalizedNumberFormatter&& formatter) && {
    Derived move(std::move(*this));
    move.fMacros.formatter1 = std::move(formatter);
    move.fMacros.singleFormatter = false;
    touchRangeLocales(move.fMacros);
    return move;
}

template<typename Derived>
Derived NumberRangeFormatterSettings<Derived>::numberFormatterSecond(const UnlocalizedNumberFormatter& formatter) const& {
    Derived copy(*this);
    copy.fMacros.formatter2 = formatter;
    copy.fMacros.singleFormatter = false;
    touchRangeLocales(copy.fMacros);
    return copy;
}

template<typename Derived>
Derived NumberRangeFormatterSettings<Derived>::numberFormatterSecond(const UnlocalizedNumberFormatter& formatter) && {
    Derived move(std::move(*this));
    move.fMacros.formatter2 = formatter;
    move.fMacros.singleFormatter = false;
    touchRangeLocales(move.fMacros);
    return move;
}

template<typename Derived>
Derived NumberRangeFormatterSettings<Derived>::numberFormatterSecond(UnlocalizedNumberFormatter&& formatter) const& {
    Derived copy(*this);
    copy.fMacros.formatter2 = std::move(formatter);
    copy.fMacros.singleFormatter = false;
    touchRangeLocales(copy.fMacros);
    return copy;
}

template<typename Derived>
Derived NumberRangeFormatterSettings<Derived>::numberFormatterSecond(UnlocalizedNumberFormatter&& formatter) && {
    Derived move(std::move(*this));
    move.fMacros.formatter2 = std::move(formatter);
    move.fMacros.singleFormatter = false;
    touchRangeLocales(move.fMacros);
    return move;
}

template<typename Derived>
Derived NumberRangeFormatterSettings<Derived>::collapse(UNumberRangeCollapse collapse) const& {
    Derived copy(*this);
    copy.fMacros.collapse = collapse;
    return copy;
}

template<typename Derived>
Derived NumberRangeFormatterSettings<Derived>::collapse(UNumberRangeCollapse collapse) && {
    Derived move(std::move(*this));
    move.fMacros.collapse = collapse;
    return move;
}

template<typename Derived>
Derived NumberRangeFormatterSettings<Derived>::identityFallback(UNumberRangeIdentityFallback identityFallback) const& {
    Derived copy(*this);
    copy.fMacros.identityFallback = identityFallback;
    return copy;
}

template<typename Derived>
Derived NumberRangeFormatterSettings<Derived>::identityFallback(UNumberRangeIdentityFallback identityFallback) && {
    Derived move(std::move(*this));
    move.fMacros.identityFallback = identityFallback;
    return move;
}

// Declare all classes that implement NumberRangeFormatterSettings
// See https://stackoverflow.com/a/495056/1407170
template
class icu::number::NumberRangeFormatterSettings<icu::number::UnlocalizedNumberRangeFormatter>;
template
class icu::number::NumberRangeFormatterSettings<icu::number::LocalizedNumberRangeFormatter>;


UnlocalizedNumberRangeFormatter NumberRangeFormatter::with() {
    UnlocalizedNumberRangeFormatter result;
    return result;
}

LocalizedNumberRangeFormatter NumberRangeFormatter::withLocale(const Locale& locale) {
    return with().locale(locale);
}


template<typename T> using NFS = NumberRangeFormatterSettings<T>;
using LNF = LocalizedNumberRangeFormatter;
using UNF = UnlocalizedNumberRangeFormatter;

UnlocalizedNumberRangeFormatter::UnlocalizedNumberRangeFormatter(const UNF& other)
        : UNF(static_cast<const NFS<UNF>&>(other)) {}

UnlocalizedNumberRangeFormatter::UnlocalizedNumberRangeFormatter(const NFS<UNF>& other)
        : NFS<UNF>(other) {
    // No additional fields to assign
}

// Make default copy constructor call the NumberRangeFormatterSettings copy constructor.
UnlocalizedNumberRangeFormatter::UnlocalizedNumberRangeFormatter(UNF&& src) U_NOEXCEPT
        : UNF(static_cast<NFS<UNF>&&>(src)) {}

UnlocalizedNumberRangeFormatter::UnlocalizedNumberRangeFormatter(NFS<UNF>&& src) U_NOEXCEPT
        : NFS<UNF>(std::move(src)) {
    // No additional fields to assign
}

UnlocalizedNumberRangeFormatter& UnlocalizedNumberRangeFormatter::operator=(const UNF& other) {
    NFS<UNF>::operator=(static_cast<const NFS<UNF>&>(other));
    // No additional fields to assign
    return *this;
}

UnlocalizedNumberRangeFormatter& UnlocalizedNumberRangeFormatter::operator=(UNF&& src) U_NOEXCEPT {
    NFS<UNF>::operator=(static_cast<NFS<UNF>&&>(src));
    // No additional fields to assign
    return *this;
}

// Make default copy constructor call the NumberRangeFormatterSettings copy constructor.
LocalizedNumberRangeFormatter::LocalizedNumberRangeFormatter(const LNF& other)
        : LNF(static_cast<const NFS<LNF>&>(other)) {}

LocalizedNumberRangeFormatter::LocalizedNumberRangeFormatter(const NFS<LNF>& other)
        : NFS<LNF>(other) {
    // No additional fields to assign
}

LocalizedNumberRangeFormatter::LocalizedNumberRangeFormatter(LocalizedNumberRangeFormatter&& src) U_NOEXCEPT
        : LNF(static_cast<NFS<LNF>&&>(src)) {}

LocalizedNumberRangeFormatter::LocalizedNumberRangeFormatter(NFS<LNF>&& src) U_NOEXCEPT
        : NFS<LNF>(std::move(src)) {
    // Steal the compiled formatter
    LNF&& _src = static_cast<LNF&&>(src);
    fImpl = _src.fImpl;
    _src.fImpl = nullptr;
}

LocalizedNumberRangeFormatter& LocalizedNumberRangeFormatter::operator=(const LNF& other) {
    NFS<LNF>::operator=(static_cast<const NFS<LNF>&>(other));
    // Do not steal; just clear
    delete fImpl;
    fImpl = nullptr;
    return *this;
}

LocalizedNumberRangeFormatter& LocalizedNumberRangeFormatter::operator=(LNF&& src) U_NOEXCEPT {
    NFS<LNF>::operator=(static_cast<NFS<LNF>&&>(src));
    // Steal the compiled formatter
    delete fImpl;
    fImpl = src.fImpl;
    src.fImpl = nullptr;
    return *this;
}


LocalizedNumberRangeFormatter::~LocalizedNumberRangeFormatter() {
    delete fImpl;
}

LocalizedNumberRangeFormatter::LocalizedNumberRangeFormatter(const RangeMacroProps& macros, const Locale& locale) {
    fMacros = macros;
    fMacros.locale = locale;
    touchRangeLocales(fMacros);
}

LocalizedNumberRangeFormatter::LocalizedNumberRangeFormatter(RangeMacroProps&& macros, const Locale& locale) {
    fMacros = std::move(macros);
    fMacros.locale = locale;
    touchRangeLocales(fMacros);
}

LocalizedNumberRangeFormatter UnlocalizedNumberRangeFormatter::locale(const Locale& locale) const& {
    return LocalizedNumberRangeFormatter(fMacros, locale);
}

LocalizedNumberRangeFormatter UnlocalizedNumberRangeFormatter::locale(const Locale& locale)&& {
    return LocalizedNumberRangeFormatter(std::move(fMacros), locale);
}


FormattedNumberRange LocalizedNumberRangeFormatter::formatFormattableRange(
        const Formattable& first, const Formattable& second, UErrorCode& status) const {
    if (U_FAILURE(status)) {
        return FormattedNumberRange(U_ILLEGAL_ARGUMENT_ERROR);
    }

    auto results = new UFormattedNumberRangeData();
    if (results == nullptr) {
        status = U_MEMORY_ALLOCATION_ERROR;
        return FormattedNumberRange(status);
    }

    first.populateDecimalQuantity(results->quantity1, status);
    if (U_FAILURE(status)) {
        return FormattedNumberRange(status);
    }

    second.populateDecimalQuantity(results->quantity2, status);
    if (U_FAILURE(status)) {
        return FormattedNumberRange(status);
    }

    formatImpl(*results, first == second, status);

    // Do not save the results object if we encountered a failure.
    if (U_SUCCESS(status)) {
        return FormattedNumberRange(results);
    } else {
        delete results;
        return FormattedNumberRange(status);
    }
}

void LocalizedNumberRangeFormatter::formatImpl(
        UFormattedNumberRangeData& results, bool equalBeforeRounding, UErrorCode& status) const {
    if (fImpl == nullptr) {
        // TODO: Fix this once the atomic is ready!
        auto* nonConstThis = const_cast<LocalizedNumberRangeFormatter*>(this);
        nonConstThis->fImpl = new NumberRangeFormatterImpl(fMacros, status);
        if (U_FAILURE(status)) {
            return;
        }
        if (fImpl == nullptr) {
            status = U_MEMORY_ALLOCATION_ERROR;
            return;
        }
    }
    fImpl->format(results, equalBeforeRounding, status);
}


FormattedNumberRange::FormattedNumberRange(FormattedNumberRange&& src) U_NOEXCEPT
        : fResults(src.fResults), fErrorCode(src.fErrorCode) {
    // Disown src.fResults to prevent double-deletion
    src.fResults = nullptr;
    src.fErrorCode = U_INVALID_STATE_ERROR;
}

FormattedNumberRange& FormattedNumberRange::operator=(FormattedNumberRange&& src) U_NOEXCEPT {
    delete fResults;
    fResults = src.fResults;
    fErrorCode = src.fErrorCode;
    // Disown src.fResults to prevent double-deletion
    src.fResults = nullptr;
    src.fErrorCode = U_INVALID_STATE_ERROR;
    return *this;
}

UnicodeString FormattedNumberRange::toString(UErrorCode& status) const {
    if (U_FAILURE(status)) {
        return ICU_Utility::makeBogusString();
    }
    if (fResults == nullptr) {
        status = fErrorCode;
        return ICU_Utility::makeBogusString();
    }
    return fResults->string.toUnicodeString();
}

Appendable& FormattedNumberRange::appendTo(Appendable& appendable, UErrorCode& status) const {
    if (U_FAILURE(status)) {
        return appendable;
    }
    if (fResults == nullptr) {
        status = fErrorCode;
        return appendable;
    }
    appendable.appendString(fResults->string.chars(), fResults->string.length());
    return appendable;
}

UBool FormattedNumberRange::nextFieldPosition(FieldPosition& fieldPosition, UErrorCode& status) const {
    if (U_FAILURE(status)) {
        return FALSE;
    }
    if (fResults == nullptr) {
        status = fErrorCode;
        return FALSE;
    }
    // NOTE: MSVC sometimes complains when implicitly converting between bool and UBool
    return fResults->string.nextFieldPosition(fieldPosition, status) ? TRUE : FALSE;
}

void FormattedNumberRange::getAllFieldPositions(FieldPositionIterator& iterator, UErrorCode& status) const {
    FieldPositionIteratorHandler fpih(&iterator, status);
    getAllFieldPositionsImpl(fpih, status);
}

void FormattedNumberRange::getAllFieldPositionsImpl(
        FieldPositionIteratorHandler& fpih, UErrorCode& status) const {
    if (U_FAILURE(status)) {
        return;
    }
    if (fResults == nullptr) {
        status = fErrorCode;
        return;
    }
    fResults->string.getAllFieldPositions(fpih, status);
}

UnicodeString FormattedNumberRange::getFirstDecimal(UErrorCode& status) const {
    if (U_FAILURE(status)) {
        return ICU_Utility::makeBogusString();
    }
    if (fResults == nullptr) {
        status = fErrorCode;
        return ICU_Utility::makeBogusString();
    }
    return fResults->quantity1.toScientificString();
}

UnicodeString FormattedNumberRange::getSecondDecimal(UErrorCode& status) const {
    if (U_FAILURE(status)) {
        return ICU_Utility::makeBogusString();
    }
    if (fResults == nullptr) {
        status = fErrorCode;
        return ICU_Utility::makeBogusString();
    }
    return fResults->quantity2.toScientificString();
}

UNumberRangeIdentityResult FormattedNumberRange::getIdentityResult(UErrorCode& status) const {
    if (U_FAILURE(status)) {
        return UNUM_IDENTITY_RESULT_NOT_EQUAL;
    }
    if (fResults == nullptr) {
        status = fErrorCode;
        return UNUM_IDENTITY_RESULT_NOT_EQUAL;
    }
    return fResults->identityResult;
}

FormattedNumberRange::~FormattedNumberRange() {
    delete fResults;
}



#endif /* #if !UCONFIG_NO_FORMATTING */